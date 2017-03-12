#include <cstdlib>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

int main(int argc, char **argv)
{
 boost::numeric::ublas::matrix<float> m1(4, 3), m2(3, 2);
 for (unsigned i = 0; i < m1.size1(); ++i)
  for (unsigned j = 0; j < m1.size2(); ++j)
  m1(i, j) = 2 * i + j;
 std::cout << "m1 = "<< m1 << '\n';

 for (unsigned i = 0; i < m2.size1(); ++i)
  for (unsigned j = 0; j < m2.size2(); ++j)
  m2(i, j) =  i + j + 1;
 std::cout << "m2 = "<< m2 << '\n';

 std::cout << "prod(m1, m2) = " << prod(m1, m2) << '\n';
 
 
  auto directory_path = "./";
  boost::filesystem::path dir_path(directory_path);
  auto is_path = boost::filesystem::is_directory(dir_path);
  std::string temp_chars;
  for (auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(dir_path), {})) {
    auto temp_path = entry.path();
    std::cout << temp_path.string() << '\n';
  }
 
}
