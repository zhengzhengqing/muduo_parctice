#pragma once
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <map>

using namespace std;

class Stock
{
    public:
        Stock() = default;
        explicit Stock(const string& value):value_(value){} 
        ~Stock(){cout <<"stock destroy" <<endl;}
        void print(){cout <<"value = " <<value_ <<endl;}
    public:
        string value_;
};

class StockFactory : public enable_shared_from_this<StockFactory> // 解决StockFactory 先于 Stock对象析构
{
    public:
        shared_ptr<Stock> get(const string& key)
        {
            shared_ptr<Stock> p_stock;
            std::unique_lock<std::mutex> lock(mutex_);
            weak_ptr<Stock> &w_stock = stocks_[key] ;// 如果key不存在，会默认创建一个
            p_stock = w_stock.lock(); 
            if(!p_stock)
            {   cout <<"stock not existed" <<endl;

                // p_stock.reset(new Stock(key),
                //                std::bind(
                //                             &StockFactory::deleteStock,
                //                             this, std::placeholders::_1
                //                         )
                //              );

                // p_stock.reset(new Stock(key),
                //                std::bind(
                //                             &StockFactory::deleteStock, 
                //                             shared_from_this(),
                //                             std::placeholders::_1
                //                         )
                //              );

                p_stock.reset(new Stock(key),
                               std::bind(
                                            &StockFactory::weakDeleteCallBck,
                                            weak_ptr<StockFactory>(shared_from_this()),
                                            std::placeholders::_1
                            ));

                w_stock = p_stock;
            }
            return p_stock;   
        }

        static void weakDeleteCallBck( const weak_ptr<StockFactory>& w_ptr, Stock* stock)
        {
            shared_ptr<StockFactory> factory(w_ptr.lock());
            if(factory)
            {
                factory->deleteStock(stock);
            }
            else
            {
                cout <<"factory not exsited" <<endl;
            }
             delete stock;
        }

        void deleteStock(Stock* stock)
        {
            if(stock)
            {
                cout <<"deleteStock" <<endl;
                std::unique_lock<std::mutex> lock(mutex_);
                stocks_.erase(stock->value_);
            }
        }

        void print_size()
        {
            cout << "size = " << stocks_.size() <<endl;
        }
    
    private:
        std::mutex mutex_;
        map<string, weak_ptr<Stock>> stocks_;
};