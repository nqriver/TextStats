# TextStats
A command line tool for analyzing content attributes of text files. 

## Description and usage
General usage pattern:

```textstats.exe -f FILE [option]...```

Application expects the user to specify command line options when it is launched. It returns the results depending on
the combination of flags. The default behavior and constraints of flags are described below. 

### Flags:
<!-- TABLE_GENERATE_START -->

| Flag | Alias     	      | Description 																				|
| ---- | ---------------- | --------------------------------------------------------------------------------------------|
|  -f  | --file           | after this flag path of the analysed text file is expected                                  |
|  -n  | --newlines       | returns number of lines                                                                     |
|  -d  | --digits         | returns number of digits                                                                    |
|  -c  | --chars          | returns number of characters                                                                |
| -dd  | --numbers        | returns number of numbers                                                                   |
|  -a  | --anagrams       | returns anagrams of words specified after this flag which occur in the content of file      |
|  -p  | --palindromes    | returns palindromes from words specified after this flag which occur in the content of file |
|  -s  | --sorted         | returns words in alphabetical order                                                         |
| -rs  | --reverse-sorted | returns words in reverse alphabetical order                                                 |
|  -l  | --by-length      | precedes -s or -rs flag to change the sorting algorithm to sort by length                    |
|  -o  | --output         | after this flag path of output file is expected, saves all results to this file             |
|  -i  | --input          | after this flag path of input file is expected, gets all options data from this file	    |


The options above may be used in any combination with a few constraints:
* -f flag should be specified first and should be followed by correct source file path
* -i should be followed by correct file path
* -o flag should be followed by file path
* -a and -p flags should be specified at the end, followed by any number of words (including 0)

## Technologies
* C++

## Author
Łukasz Karasek