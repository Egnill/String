#include <Strings.h>
#include <Work.h>
#include <ctest.h>

CTEST(arithmetic_suite, income_slen_1)
{
	const int result = slen("qwert", '\0');
	const int expected = 5;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_slen_1)
{
	const int result = slen("qwerty/daa", '/');
	const int expected = 6;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_sspn_1)
{
	const int result = sspn("qwert", 0);
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_sspn_2)
{
	const int result = sspn("qwe*rt", 0);
	const int expected = 3;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_sspn_3)
{
	const int result = sspn("qwert/sdfa|asd", 0);
	const int expected = 10;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_check_number_1)
{
	const int result = check_number("qwert", '\0');
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_check_number_2)
{
	const int result = check_number("qwe12qwe", '\0');
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_check_number_3)
{
	const int result = check_number("123456", '\0');
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_check_number_4)
{
	const int result = check_number("12345as678", '\0');
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_check_1)
{
	const int result = check("/qwert/asddddddd/dasdd.c", 'l');
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_check_2)
{
	const int result = check("/wer/tyui/12345/eqw/qwe/fg/dfa/1225/zxc/adf2sdfs/sdfsdgsdgbnshfgdhdsghjsdjkgsjkdgkjs/qwerhnbiusifbsfds/12344893265/sdgsjdnislerubnsegtbiunbetgniebtbiuns/fsdfsdfsdfsdfsdgsdg/wekjsdhnb2321/ffdsfsdfwerojbifndsigsihnb516971548/fdstgbsnsigfsubt/dgfsdibnsutsfdgnbrdf.c", 'l');
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_check_3)
{
	const int result = check("/qwert/asd*dddddd/dasdd.c", 'l');
	const int expected = 10;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_check_4)
{
	const int result = check("/qwert|asddddddd/dasdd.c", 'l');
	const int expected = 6;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_check_5)
{
	const int result = check("Ca:\\dasdsfdsafksdf\\sdfsdjfsdhgfsjd\\sdgfsd.c", 'l');
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(arithmetic_suite, income_check_6)
{
	const int result = check("CA:\\dasd\\g44|dasdas\\dasd.c", 'l');
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}