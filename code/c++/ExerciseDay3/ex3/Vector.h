#ifndef _VECTOR
#define _VECTOR

class Vector 
{
 public:
  Vector(int size); 
  ~Vector();

  // some methods
  int Size(void) const;
  void zero(void);
  double norm(void) const;
  double dot(const Vector &other) const;
  void print(void);

  // overload some operators to look Matlabish
  Vector operator+(const Vector &other) const;
  void operator=(const Vector &other);
  void operator+=(double val);
  void operator+=(const Vector &other);

  double operator()(int x) const;
  double &operator()(int x);

 private:
  double *data;
  int size;
};


#endif
