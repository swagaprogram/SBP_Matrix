#pragma once
#include "Number.h"
#include <iostream>
template<class T> class Matrix;
template <typename T>

class Matrix {
private:
	
	unsigned int			rows_;
	unsigned int			columns_;
	T**						Array_;

public:
	
	Matrix() {
		rows_ = 0;
		columns_ = 0;
		Array_ = nullptr;
	}
	
	Matrix(unsigned int rows, unsigned int columns) {
		rows_ = rows;
		columns_ = columns;

		Array_ = new T*[rows];
		for (unsigned int i = 0; i < rows; ++i) {
			Array_[i] = new T[columns_];
			for (unsigned int j = 0; j < columns; ++j)
				Array_[i][j] = 0;
		}
	}
	
	Matrix(const Matrix& get) {
		rows_ = get.rows_;
		columns_ = get.columns_;
		Array_ = new T*[rows_];
		for (unsigned int i = 0; i < rows_; ++i) {
			Array_[i] = new T[columns_];
			for (unsigned int j = 0; j < columns_; ++j) {
				Array_[i][j] = get.Array_[i][j];
			}
		}
	}
	
	void setElement(unsigned int row, unsigned int column, T key) {
		Array_[row][column] = key;
	}

	void print() {
		for (unsigned int i = 0; i < rows_; ++i) {
			for (unsigned int j = 0; j < columns_; ++j) {
				std::cout << Array_[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

};