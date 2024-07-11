<!-- Test Specefications doucment for Soundex Implementation -->
# Test cases
* If empty string is given, output should return empty string i.e. ""
* If Single character input is given, output should return same as fisrt charater appended by zeroes. E.g. "A" is "A000"
* If Repeat of same character is given, output returns first character appended by zeroes. E.g. "Aaa" is "A000"
* If word is less than 4 charaters, output returns code appended by zeroes until it is 4 character code. E.g. "Set" is "S300"
* If a multiple charater word is given, output returns the code upto 4 characters. e.g. "Robert" is "R163"
*