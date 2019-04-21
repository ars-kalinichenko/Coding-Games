#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Factory {
private:
    int id;
    int owner;
    int cyborgsCount;
    int production;

public:
    Factory(int id, int owner, int cyborgsCount, int production) {
        this->id = id;
        this->owner = owner;
        this->cyborgsCount = cyborgsCount;
        this->production = production;
    }

    int get_owner() {
        return owner;
    }
    int get_cyborgsCount() {
        return cyborgsCount;
    }
    int get_production() {
        return production;
    }
    int get_id() {
        return id;
    }
};



Factory* my_max_cyborgs(vector<Factory*> factories) {
    int max = -9999999;
    auto index = 0;
    for(int i = 0; i < factories.size(); i++) {
        if (1 == factories[i]->get_owner() && factories[i]->get_cyborgsCount() > max) {
            index = i;
            max = factories[i]->get_cyborgsCount();
        }
    }
    return factories[index];
}

Factory* my_min_cyborgs(vector<Factory*> factories) {
    int min = 999999;
    auto index = 0;
    for(int i = 0; i < factories.size(); i++) {
        if (1 == factories[i]->get_owner() && factories[i]->get_cyborgsCount() < min) {
            index = i;
            min = factories[i]->get_cyborgsCount();
        }
    }
    return factories[index];
}

int main()
{
    const int neutral = 0;
    const int my = 1;
    const int entity = -1;
    int factoryCount; // the number of factories
    cin >> factoryCount; cin.ignore();
    int linkCount; // the number of links between factories
    cin >> linkCount; cin.ignore();
    for (int i = 0; i < linkCount; i++) {
        int factory1;
        int factory2;
        int distance;
        cin >> factory1 >> factory2 >> distance; cin.ignore();

    }

    // game loop
    while (1) {
        vector<Factory*> factories;
        int entityCount; // the number of entities (e.g. factories and troops)
        cin >> entityCount; cin.ignore();
        for (int i = 0; i < entityCount; i++) {
            int entityId;
            string entityType;
            int arg1;
            int arg2;
            int arg3;
            int arg4;
            int arg5;
            cin >> entityId >> entityType >> arg1 >> arg2 >> arg3 >> arg4 >> arg5; cin.ignore();
            if(entityType == "FACTORY") {
                Factory* factory = new Factory(entityId, arg1, arg2, arg3);
                factories.push_back(factory);
            }
        }


        Factory* max = my_max_cyborgs(factories);
        Factory* min = my_min_cyborgs(factories);

        cout << "WAIT";
        // to neutral factories
        for (int i = 0; i < factories.size(); i++) {
            if (max->get_owner() == my && max->get_cyborgsCount() > 10 && factories[i]->get_owner() == neutral) {
                int nerId = factories[i]->get_id();

                if(factories[i]->get_cyborgsCount() < max->get_cyborgsCount()) {
                    cout << ";MOVE " << max->get_id() << " " << nerId << " " << 2;
                }
            }
        }

        // to enemy factories
        for(int i = 0; i < factories.size(); i++) {
            if(factories[i]->get_owner() == neutral && max->get_cyborgsCount() > 30) {
                cout << ";MOVE " << max->get_id() << " " << i << " " << max->get_cyborgsCount();
            }

        }

        cout << endl;


    }
}
