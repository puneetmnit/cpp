#include <unistd.h>

namespace system {
namespace utils {
/** round the capacity to multiple of page size.
*/
  size_t roundToPageSize(size_t capacity)
  {
    long pageSize = ::sysconf(_SC_PAGESIZE);  //pagesize is alwasy power of 2
    if (pageSize < 0) return -1; //error
    long mask = pageSize - 1;
    
    return (capacity + mask) & ~mask;
  }
  
} // namespace utils
} // namespace system
