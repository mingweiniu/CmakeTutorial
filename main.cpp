#include <cstdlib>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

int main(int argc, char **argv)
{
 boost::numeric::ublas::matrix<float> m1(4, 3), m2(3, 2);
 for (unsigned i = 0; i < m1.size1(); ++i)
  for (unsigned j = 0; j < m1.size2(); ++j)
  m1(i, j) = 2 * i + j;
 std::cout << m1 << '\n';

 for (unsigned i = 0; i < m2.size1(); ++i)
  for (unsigned j = 0; j < m2.size2(); ++j)
  m2(i, j) =  i + j + 1;
 std::cout << m2 << '\n';

 std::cout << "prod(m1, m2) " << prod(m1, m2) << '\n';
 system("PAUSE");
 return 0;
}