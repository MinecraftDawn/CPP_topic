#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

tuple<int, vector<int>>
dfs(vector<vector<float>> *items, int index, double *maxPrice, double curPrice, const int *totalSize, int weight) {

    if (index == items->size()) {
        *maxPrice = max(*maxPrice, curPrice);
        return {curPrice, vector<int>()};
    }

    int itemID = (*items)[index][0];
    int itemWeight = (*items)[index][1];
    int itemPrice = (*items)[index][2];
    if (weight + itemWeight > *totalSize) {
        *maxPrice = max(*maxPrice, curPrice);

        // No take current item
        return dfs(items, index + 1, maxPrice, curPrice, totalSize, weight);;
    }

//    // Take current item
    int takeWeight, ntWeight;
    vector<int> takeSqu, ntSqu;
    tie(takeWeight, takeSqu) = dfs(items, index + 1, maxPrice, curPrice + itemPrice, totalSize, weight + itemWeight);

    // No take current item
    tie(ntWeight, ntSqu) = dfs(items, index + 1, maxPrice, curPrice, totalSize, weight);

    if (takeWeight > ntWeight) {
        takeSqu.push_back(itemID);
        return {takeWeight, takeSqu};
    } else {

        return {ntWeight, ntSqu};
    }

}

int main() {
    int size;
    vector<vector<float>> items;

    cin >> size;
    while(!cin.eof()){

        int id,weight,value;
        cin >> id >> weight >> value;
        if (id == -1 && weight == -1 && value == -1) break;

        vector<float> tmp({(float) id,(float) weight,(float) value, (float) value/weight});
        items.push_back(tmp);
    }

    sort(items.begin(), items.end(),
         [](const std::vector<float> &a, const std::vector<float> &b) {
             return a[3] > b[3];
         });

    double maxPrice = INT32_MIN;
    int weight;
    vector<int> squ;
    tie(weight, squ) = dfs(&items, 0, &maxPrice, 0, &size, 0);

    reverse(squ.begin(), squ.end());
    for (int i = 0; i < squ.size() - 1; ++i) {
        cout << squ[i] << " ";
    }
    cout << squ[squ.size() - 1] << endl;

    cout << maxPrice << endl;
}