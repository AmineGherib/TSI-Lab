#include <iostream>
#include <vector>
#include <fstream>

template <typename K>
void fillMatrix(std::vector<std::vector<K>> data, std::ifstream file, bool fail) {
	
	if(!file.is_open()) {
			MessageBox::Show("Error! File is closed.","Error Message");
			*fail = true;
			return;
	}

	int n, m;
    std::string ColHeadX, ColHeadY;

    file >> n >> m >> ColHeadX >> ColHeadY;
    
    for(int loop=0, x=0, y=0;loop < (n*m) && (file >> data[x][y]);) {
       ++loop
       x = loop % n;
       y = loop / n;
    }
}

int fill_main() {
    std::ifstream file("input.txt");
	std::vector<std::vector<double>> data(n,std::vector<double>(m));
	bool fail = false;

	fillMatrix(data, file, &fail);
	if(fail) return 0;
}