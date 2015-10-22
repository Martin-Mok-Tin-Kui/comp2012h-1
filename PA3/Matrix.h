class Matrix { // Matrix class
 public:
  explicit Matrix(int rows = 0, int cols = 0);
  // constructor
  Matrix( const Matrix & mt); // copy constructor
  ~Matrix(); // destructor
  int rows() const; // return the number of rows of the matrix
  int cols() const; // return the number of columns of the matrix
  double & el(int i, int j) const; // access (i, j)th element
  void assign(const Matrix & op); // copy values from op
  Matrix mul(const Matrix & op) const; // multiplication of matrices
  Matrix transpose() const; // the transpose of matrix
  Matrix inverse() const; // the inverse of matrix

  // Add your public member functions, if any, in the following
  double det() const; // Get determinant of the matrix
  void print(); // Print the matrix to std::cout
  Matrix getMinor(const int & minor_r, const int & minor_c) const; // Get the matrix without the (minor_r)'th row and the (minor_c)'th column
  Matrix cofactor() const; // Get the cofactor matrix
  Matrix solveForX(const Matrix & b) const;

  // Set matrix to useful values
  void setIdentity(); // Set the matrix to the identity matrix
  void setZero();

 private:
  double **elm; // matrix elements
  int r; // number of rows
  int c; // number of columns
  // Add your private data members and private member functions,
  // if any, in the following
};
