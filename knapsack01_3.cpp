#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef struct Pack {
    double priority;
    int index;
    double price;
    int weight;
    vector<int> id;

    Pack() {}

    Pack(double priority, int index, double price, int weight, vector<int> id) {
        this->priority = priority;
        this->index = index;
        this->price = price;
        this->weight = weight;
        this->id = id;
    }

    bool operator<(const Pack &p) {
        return this->priority < p.priority;
    }

    bool operator>(const Pack &p) {
        return this->priority > p.priority;
    }

};


float predictPrice(vector<vector<float>> *items, int index, double curPrice, const int *totalSize, int weight) {
    while (weight < *totalSize && index < items->size()) {
        double w = (*items)[index][1];
        double v = (*items)[index][2];
        double vu = (*items)[index][3];
        if (*totalSize - weight > w) {
            curPrice += v;
            weight += w;

        } else {
            curPrice += vu * (*totalSize - weight);
            weight = *totalSize;
        }
        index++;
    }
    return curPrice;
}

int main() {
    int size;
    vector<vector<float>> items;

    cin >> size;
    while (!cin.eof()) {

        int id, weight, value;
        cin >> id >> weight >> value;
        if (id == -1 && weight == -1 && value == -1) break;

        vector<float> tmp({(float) id, (float) weight, (float) value, (float) value / weight});
        items.push_back(tmp);
    }

    vector<Pack> priorityQueue;

    sort(items.begin(), items.end(),
         [](const std::vector<float> &a, const std::vector<float> &b) {
             return a[3] > b[3];
         });

    // priority, index, curPrice, weight
    priorityQueue.push_back(Pack(0., 0, 0., 0, vector<int>()));

    while (priorityQueue.size()) {
        Pack pack = priorityQueue[0];
        vector<int> ids = pack.id;
        int index = pack.index;
        vector<float> i = items[index];
        int w = i[1];
        int p = i[2];
        int curID = i[0];

        if (index == items.size() - 1) {
            break;
        }

        pop_heap(priorityQueue.begin(), priorityQueue.end());
        priorityQueue.pop_back();

        if (pack.weight + w <= size) {
            float takePredict = predictPrice(&items, index + 1, pack.price, &size, pack.weight);
            vector<int> takeID = ids;
            takeID.push_back(curID);
            priorityQueue.push_back(Pack(takePredict, pack.index + 1, pack.price + p, pack.weight + w, takeID));
            push_heap(priorityQueue.begin(), priorityQueue.end());
        }
        float notTakePredict = predictPrice(&items, index + 1, pack.price, &size, pack.weight);
        vector<int> notTakeID = ids;
        priorityQueue.push_back(Pack(notTakePredict, pack.index + 1, pack.price, pack.weight, notTakeID));
        push_heap(priorityQueue.begin(), priorityQueue.end());
    }


    Pack pack = priorityQueue[0];
    vector<int> ids = pack.id;

    for (int i = 0; i < ids.size()-1; ++i) {
        cout << ids[i] << " ";
    }
    cout << ids[ids.size()-1] << endl;

    cout << pack.price;
    
//    for(vector<float> v: items){
//        for(float f: v){
//            cout << f << " ";
//        }
//        cout << endl;
//    }


//    double maxPrice = INT32_MIN;
//    double weight;
//    vector<int> squ;
//    Pack p;
//    p = dfs(&items, 0, &maxPrice, 0, &size, 0);
//    weight = p.price;
//    squ = p.id;
//
//    reverse(squ.begin(), squ.end());
//    for (int i = 0; i < squ.size() - 1; ++i) {
//        cout << squ[i] << " ";
//    }
//    cout << squ[squ.size() - 1] << endl;
//
//    cout << maxPrice << endl;
}