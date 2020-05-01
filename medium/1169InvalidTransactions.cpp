//
// Created by timruning on 2020/4/14.
//
#include "../import_iostream.h"
#include "../common/common.cpp"
#include <tuple>

class Solution {
public:

//    vector<string> invalidTransactions(vector<string> &transactions) {
//        map<string,vector<tuple<int,string>>> m;
//        vector<string> result;
//        for (int i = 0; i < transactions.size(); i++) {
//            vector<string> tmp ;
//            split(transactions[i],tmp,",");
//            int a = std::stoi(tmp[1]);
//            int b = std::stoi(tmp[2]);
//
//            if(m.find(tmp[0]) != m.end()){
//
//            }else{
//                vector<tuple<int,string>> x;
//                tuple.
//                x.push_back(tuple(a,tmp[3]));
//                 m.insert()
//            }
//
//            if(b-a >= 1000){
//                result.push_back(transactions[i]);
//            }
//        }
//        return result;
//    }
//    struct Trans {
//        string name, city;
//        int time, amount;
//
//        string toString() {
//            stringstream ss;
//            ss << name << "," << time << "," << amount << "," << city;
//            return ss.str();
//        }
//    };
//
//    using VS = vector<string>;
//    using Set = unordered_set<string>;

//    VS invalidTransactions(VS &T, vector<Trans> A = {}, Set set = {}, VS ans = {}) {
//        int N = T.size();
//        auto getTrans = [](string t) {
//            transform(t.begin(), t.end(), t.begin(), [](auto c) { return c == ',' ? ' ' : c; });
//            stringstream ss;
//            ss << t;
//            Trans trans;
//            ss >> trans.name >> trans.time >> trans.amount >> trans.city;
//            return trans;
//        };
//        transform(T.begin(), T.end(), back_inserter(A), [&](auto &t) { return getTrans(t); });
//        for (auto &trans: A)
//            if (trans.amount > 1000)
//                set.insert(trans.toString()); // amount exceeds 1000 ❌
//        for (auto i{0}; i < N; ++i)
//            for (auto j{0}; j < N; ++j)
//                if (i != j && A[i].name == A[j].name && A[i].city != A[j].city && abs(A[i].time - A[j].time) <= 60)
//                    set.insert(A[i].toString()), // A[i] and A[j] occur within 60 minutes of each other ❌
//                            set.insert(A[j].toString());
//        return {set.begin(), set.end()};
//    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map <string, multimap<int,string> > m;
        vector <string> res;
        vector <string> names(transactions.size());
        vector <string> cities(transactions.size());
        vector <int> amounts(transactions.size());
        vector <int> times(transactions.size());
        int j = 0;
        for(auto w : transactions)
        {
            int i = 0;
            string name,city;
            int amount,time;
            while(i < w.length() and w[i] != ',') name.push_back(w[i++]);
            ++i;
            string aux;
            while(i < w.length() and w[i] != ',') aux.push_back(w[i++]);
            time = stoi(aux);
            aux = "";
            ++i;
            while(i < w.length() and w[i] != ',') aux.push_back(w[i++]);
            amount = stoi(aux);
            ++i;
            while(i < w.length() and w[i] != ',') city.push_back(w[i++]);
            names[j] = name;
            cities[j] = city;
            amounts[j] = amount;
            times[j] = time;
            auto ww = m.find(name);
            if(ww == m.end())
            {
                multimap <int, string> mm; mm.insert(make_pair(time,city));
                m[name] = mm;
            }
            else
            {
                m[name].insert(make_pair(time,city));
            }
            j++;
        }

        j = 0;

        for(auto w : transactions)
        {

            if(amounts[j] > 1000) res.push_back(w);
            else
            {
                auto ww = m.find(names[j]);
                auto www = (ww->second).lower_bound(times[j] - 60);
                bool found = false;
                for(auto k = www; k != (ww->second).end() and k -> first <= times[j]+60 and not found; ++k)
                {
                    if(k -> second != cities[j]) found = true;
                }
                if(found) res.push_back(w);
            }
            ++j;
        }

        return res;

    }
};