#include "src/Headers/LoadData.h"
#include "src/Headers/Menu.h"

int main() {
    bool RunMenu = true;
    if (RunMenu) {
        LoadData data;
        data.loadData_Classes_per_UC();
        data.loadData_Classes();
        data.loadData_Students_Classes();
        for (int i = 0; i < 100; ++i) cout << "-";
        Menu menu(data);
        menu.MainMenu(15);
    }
    return 0;
}
