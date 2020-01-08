#include<bits/stdc++.h>

int main(){
    std::vector<int> vector;
    for(int i = 0; i < 5; i++)
        vector.push_back(i);
    std::unordered_map<int, std::vector<int>> umap;
    std::pair<int, std::vector<int>> aux;
    umap.insert(std::make_pair(1, vector));
    for(auto it = umap.begin(); it != umap.end(); it++){
        std::cout << it->first << " ";
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            std::cout << *it2 << " ";
    }
    std::cout << "ajung aici" << std::endl;
    return 0;
}