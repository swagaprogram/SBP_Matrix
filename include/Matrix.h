#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

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
							~Matrix() {
		for (unsigned int i = 0; i < rows_; ++i) {
			delete[] Array_[i];
		}
		delete[] Array_;
	}
	
	void					setElement(unsigned int row, unsigned int column, T key) {
		Array_[row][column] = key;
	}
	void					print() {
		for (unsigned int i = 0; i < rows_; ++i) {
			for (unsigned int j = 0; j < columns_; ++j) {
				std::cout << Array_[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	T						getElement(unsigned int row, unsigned int column) {
		return Array_[row][column];
	}

	Matrix<T>				operator+ (const Matrix& mat) const {
		try {
			if ((rows_ == mat.rows_) && (columns_ == mat.columns_)) {
				Matrix getRes(rows_, columns_);
				for (unsigned int i = 0; i < rows_; ++i)
					for (unsigned int j = 0; j < columns_; ++j)
						getRes.Array_[i][j] = Array_[i][j] + mat.Array_[i][j];
				return getRes;
			}
			else {
				throw "Matrixes are not identical\nFirst matrix:\n";
			}
		}
		catch (char *msg) {
			std::cout << "Error: " << msg;
			return *this;
		}

	}
	Matrix<T>				operator* (const Matrix& mat) const {
		try {
			if ((columns_ == mat.rows_)) {
				Matrix getRes(rows_, mat.columns_);
				for (unsigned int i = 0; i < rows_; ++i) {
					for (unsigned int j = 0; j < mat.columns_; ++j)
						for (unsigned int k = 0; k < columns_; ++k)
							getRes.Array_[i][j] = getRes.Array_[i][j] + (Array_[i][k] * mat.Array_[k][j]);
				}
				return getRes;
			}
			else {
				throw "!These matrixes can't be multiplied!\nFirst matrix:\n";
			}
		}
		catch (char *msg) {
			std::cout << "Error" << msg;
			return *this;
		}
	}
	Matrix<T>				operator* (T num) {
		Matrix getRes(rows_, columns_);
		for (unsigned int i = 0; i < rows_; ++i)
			for (unsigned int j = 0; j < columns_; ++j)
				getRes.Array_[i][j] = Array_[i][j] * num;
		return getRes;
	}
	Matrix<T>&				operator= (const Matrix& right) {
		if (this == &right) {
			return *this;
		}
		for (unsigned int i = 0; i < rows_; ++i) {
			delete[]Array_[i];
		}
		delete[]Array_;
		Array_ = new T*[right.rows_];
		for (unsigned int i = 0; i < right.rows_; ++i) {
			Array_[i] = new T[right.columns_];
			for (unsigned int j = 0; j < right.columns_; ++j)
				Array_[i][j] = right.Array_[i][j];
		}
		rows_ = right.rows_;
		columns_ = right.rows_;
		return *this;
	}
	bool					operator==(const Matrix& right) const {
		if ((rows_ == right.rows_) && (columns_ == right.columns_)) {
			for (unsigned int i = 0; i < rows_; ++i)
				for (unsigned int j = 0; j < columns_; ++j) {
					if (Array_[i][j] != right.Array_[i][j]) { return false; }
				}
		}
		else return false;
	}
	
	Matrix<T>				transpose() {
		Matrix<T> getRes(columns_, rows_);
		for (unsigned int i = 0; i < rows_; ++i)
			for (unsigned int j = 0; j < columns_; ++j)
				getRes.Array_[j][i] = Array_[i][j];
		return getRes;
	}
};

#endif
