#include <stdio.h>
#include <string.h>



#define ASSERT_CONCAT_(a, b) a##b
#define ASSERT_CONCAT(a, b) ASSERT_CONCAT_(a, b)
/* These can't be used after statements in c89. */
#ifdef __COUNTER__
  #define STATIC_ASSERT(e,m) \
    ;enum { ASSERT_CONCAT(static_assert_, __COUNTER__) = 1/(!!(e)) }
#else
  /* This can't be used twice on the same line so ensure if using in headers
   * that the headers are not included twice (by wrapping in #ifndef...#endif)
   * Note it doesn't cause an issue when used on same line of separate modules
   * compiled with gcc -combine -fwhole-program.  */
  #define STATIC_ASSERT(e,m) \
    ;enum { ASSERT_CONCAT(assert_line_, __LINE__) = 1/(!!(e)) }
#endif



int main(void) {

    char dest[5];
    char src[5]="hello"; //Not NUL terminated

    STATIC_ASSERT(sizeof(dest)==5, "size of correct");

    dest[sizeof(dest)-1]='\0'; //for later check
    (void) strncpy(dest, src, sizeof(dest));
    if (dest[sizeof(dest)-1]!='\0'); //truncated
    dest[sizeof(dest)-1]='\0'; //should always do this

    printf("%s\n", dest);

    int required = snprintf(dest, sizeof(dest), "%s", src);
    if (required >= sizeof(dest)); //truncated

    printf("%s\n", dest);
}
