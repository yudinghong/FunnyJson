//
// Created by Administrator on 2022/5/31.
//

#ifndef FUNNY_JSON_FUNNYJSONOBJECT_H
#define FUNNY_JSON_FUNNYJSONOBJECT_H

#include <vector>
#include <map>
#include <string>
#include "FunnyJsonEnum.h"

using std::vector;
using std::map;
using std::string;
using std::stoi;
using std::stod;
using std::to_string;

namespace {
    class FunnyJsonObject;
    class FunnyJsonArray;
    class FunnyJsonValue;

    class FunnyJsonObject {
    public:
        explicit FunnyJsonObject();
        // 往json中插入数据
        void insert(string key, int value);
        void insert(string key, double value);
        void insert(string key, string value);
        void insert(string key, bool value);
        void insert(string key, FunnyJsonArray value);
        void insert(string key, FunnyJsonObject value);
        void insertNull(string key);
        void remove(string key);

    private:
        map<string, FunnyJsonValue> obj;
    };

    class FunnyJsonArray {
    public:
        explicit FunnyJsonArray();
        struct Iterator {
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = FunnyJsonValue;
            using reference = const FunnyJsonValue&;
            using pointer = FunnyJsonValue*;
            // 构造函数
            Iterator(pointer p);
            // 拷贝赋值函数
            Iterator& operator=(const Iterator& it);
            // 等于运算符
            bool operator==(const Iterator& it) const;
            // 不等于运算符
            bool operator!=(const Iterator& it) const;
            // 前缀自加
            Iterator& operator++();
            // 后缀自加
            Iterator operator ++(int);
            // 前缀自减
            Iterator& operator--();
            // 后缀自减
            Iterator operator --(int);
            // 取值运算
            FunnyJsonValue& operator*();
        private:
            // 定义一个指针
            pointer ptr;
        };
        Iterator begin();
        Iterator end();
    private:
        vector<FunnyJsonValue> valueArray;
    };

    class FunnyJsonValue {
    public:
        explicit FunnyJsonValue();
        explicit FunnyJsonValue(int value);
        explicit FunnyJsonValue(double value);
        explicit FunnyJsonValue(bool value);
        explicit FunnyJsonValue(string value);
        explicit FunnyJsonValue(FunnyJsonArray value);
        explicit FunnyJsonValue(FunnyJsonObject value);

        // 转换成c++类型
        string toString(bool &success);
        int toInt(bool &success);
        double toDouble(bool &success);
        bool toBool(bool &success);
        FunnyJsonArray toArray(bool &success);
        FunnyJsonObject toObject(bool &success);

        // 判断类别
        bool isNull();
        bool isNumber();
        bool isObject();
        bool isArray();
        bool isBool();
        bool isString();

        void prettyPrint();

    private:
        FunnyJson::JSON_VALUE_TYPE valueType;
        union {
            int iValue;
            double dValue;
            bool bValue;
        };
        string sValue;
        FunnyJsonObject objValue;
        FunnyJsonArray arrayValue;
    };

}


#endif //FUNNY_JSON_FUNNYJSONOBJECT_H
