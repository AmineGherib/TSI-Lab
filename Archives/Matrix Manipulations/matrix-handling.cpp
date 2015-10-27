#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <random>

template <typename T>
void iFillMatrix(std::vector<std::vector<T> >* data, std::ifstream& file, bool *fail) {
	
	if(!file.is_open()) {
		std::cout << "Error! File is closed." << std::endl;
		*fail = true; return;
	}
	
	while(file) {
		std::string line;
		if(!getline(file, line)) break;
		std::istringstream ss(line);
		std::vector<T> row;
		
		while(ss) 
		{
			std::string s;
			if(!getline(ss, s)) break;
			
			int length = s.size();
			const char *constant_s = s.c_str();
			char array_s[length];
			strcpy(array_s, constant_s);
			
			char *tok;
			tok = strtok(array_s, " ");
		
			std::istringstream iss(tok); 
			T n;

			while(iss >> n) row.push_back(n);
			data->push_back(row);
		}	
	}
}

void dFillMatrix(std::vector<std::vector<double> >* data, std::ifstream& file, bool *fail) {
	
	if(!file.is_open()) {
		std::cout << "Error! File is closed." << std::endl;
		*fail = true; return;
	}
	
	while(file) {
		std::string line;
		if(!getline(file, line)) break;
		std::istringstream ss(line);
		std::vector<double> row;
		
		while(ss) 
		{
			std::string s;
			if(!getline(ss, s)) break;
			
			int length = s.size();
			char array_s[length];
			strcpy(array_s, s.c_str());
			
			char *tok;
			tok = strtok(array_s, " \t");
			while(tok != NULL) {
				const char* contok = tok;
				std::string svalue(contok);
				double value = std::stod(svalue);	
				row.push_back(value);
				tok = strtok(NULL, " \t");
			}
		data->push_back(row);
		}	
	}
}
template <typename T>
void printMatrix(std::vector<std::vector<T> > matrix) {

	for(int i = 0; i < matrix.size(); ++i) {
		for(int j = 0; j < matrix[i].size(); ++j)
			std::cout << std::setw(-3) << matrix[i][j] << "\t";
		std::cout << std::endl;
	}
}

template <typename T>
void filePrintMatrix(std::vector<std::vector<T> > matrix) {
	std::ofstream output("outputTable.txt");
	for(int i = 0; i < matrix.size(); ++i) {
		for(int j = 0; j < matrix[i].size(); ++j)
			output << std::setw(-3) << matrix[i][j] << "\t";
		output << std::endl;
	}
	output.close();
}
template <class T, class K>
void scalarMultiply(std::vector<std::vector<T> > &matrix, K scalar) {
	for(int i = 0; i < matrix.size(); ++i) {
		for(int j = 0; j < matrix[i].size(); ++j)
			matrix[i][j] *= scalar;
	}
}

template <typename T>
std::vector<std::vector<T> > dotProduct(std::vector<std::vector<T> > v1, std::vector<std::vector<T> > v2) {

	int nRow, nCol;
	
	std::vector<std::vector<T> > emptyContainer;
	if(v1[0].size() == v2.size()) {
		std::cout << "Valid dimensions. Commencing matrix generation..." <<std::endl;
		nRow = v1.size();
		nCol = v2[0].size();
	}

	else {
		std::cout << "Error! Invalid dimensions." << std::endl;
		return emptyContainer; 
	}

	std::vector<std::vector<T> > resultMatrix(nRow, std::vector<T>(nCol));
	for(int i=0; i<nRow; ++i) {
		for(int j=0; j<nCol; ++j) {
 			resultMatrix[i][j] = 0.0;
			for(int L=0; L<v1[0].size();++L)
				resultMatrix[i][j] += v1[i][L] * v2[L][j];
		}
	}
	std::cout << "Dot product matrix is generated!" << std::endl;
	return resultMatrix;
}

template <typename T>
std::vector<std::vector<T> > transposeMatrix(std::vector<std::vector<T> > matrix) {
	int nRow = matrix[0].size(), nCol = matrix.size();

	std::vector<std::vector<T> > transpose(nRow, std::vector<T>(nCol));
	for(int i=0; i<nRow;++i) {
		for(int j=0; j<nCol;++j) {
			transpose[i][j] = matrix[j][i];
		}
	}
	return transpose;
}


template <typename T>
T det(std::vector<std::vector<T> > matrix) {
	if(matrix.size() != matrix[0].size())return 0;
	
	T det;
	std::vector<T> col1, col2;
	col1 = matrix[0];
	col2 = matrix[1];

	matrix.push_back(col1);
	matrix.push_back(col2);

	T p_prod=1, s_prod=1;
	std::vector<T> vp_sum, vs_sum;

	for(int j=0; j < matrix[0].size(); ++j) {
				p_prod*=matrix[0][j];
				for(int d=0;d<matrix[0].size();++d)
					p_prod*=matrix[d][j+d];
				vp_sum.push_back(p_prod);
		}
	for(int l=matrix[0].size(); l>0; --l) {
				s_prod*=matrix[0][l];
				for(int d=matrix[0].size();d>0;--d)
					s_prod*=matrix[l][l-d];
				vs_sum.push_back(s_prod);
	}
	double sums=0, sump=0;
	for(int x=0;x<vs_sum.size();++x)
		sums += vs_sum[x];	
	for(int r=0;r<vp_sum.size();++r)
		sump += vp_sum[r];	
	det = sums - sump;
	return det;
}template <class T>
T vDotProduct(std::vector<T> v1, std::vector<T> v2) {
	if(v1.size() != v2.size()) {
		std::cout << "Invalid dimensions for vector dot product." << std::endl;
		return 0;
	}	
	T dProd=0;

	for(int i=0; i<v1.size(); ++i) 
		dProd += v1[i] * v2[i];
	
	return dProd;
}

template <typename T>
std::vector<T> PEAK(std::vector<std::vector<T> > data, std::vector<T> peak) {
	std::vector<T> results;
	T value;
	
	for(int i=0; i < data.size(); ++i) {	
		value = vDotProduct(data[i], peak);
		results.push_back(value);
	}
	return results;
}

template <typename K>
void randomFill(std::vector<K> &PEAK, int SIZE) {
	K val;
	std::default_random_engine generator;
	std::uniform_real_distribution<K> distribution (0.001,9.9999);

	for(int i = 0; i < SIZE; ++i) {	
		val = distribution(generator);
		PEAK.push_back(val);
	}
}

template <typename T>
void printVec(std::vector<T> victor) {
	for(int i=0;i<victor.size();++i)
		std::cout << victor[i] << std::endl;
}

template <typename T>
void filePrintVec(std::vector<T> victor) {
	std::ofstream oFile("outputVector.txt");

	for(int i=0;i<victor.size();++i)
		oFile << victor[i] << std::endl;
	oFile.close();
}

int main() {
	std::ifstream file("jobs_tab.txt");
	
	bool fail = false;

	std::vector<std::vector<double> > data, tData, dMatrix;
	dFillMatrix(&data, file, &fail);
	filePrintMatrix(data);

	if(fail) return 0;
	printMatrix(data);
	
	std::vector<double> AM_PEAK;
	randomFill(AM_PEAK, data[0].size());

	std::vector<double> outputVector =  PEAK(data, AM_PEAK);
	filePrintVec(outputVector);
	file.close();
	std::cout << "Done!" << std::endl;
}
