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

## Usage example
Considering text file ```first_match.txt``` with the following content:

```
The 1872 football match between the national teams of Scotland and England is the sport's first-ever international.
It took place on 30 November 1872 in Glasgow. 
The match was watched by 4,000 spectators and finished as a 0–0 draw.
 ```

an example program run with arguments specified as follows:
```
textstats.exe -f first_match.txt -d -dd -w -l --sorted -o result.txt --anagrams tchma
```
saves the following results to file ```result.txt``` :
```
[Number of digits] 16
[Number of numbers] 5
[Number of words] 40
[Words sorted by length]
international.
first-ever
spectators
November
football
Partick,
Glasgow.
national
finished
Scotland
England
sport's
watched
between
4,000
teams
match
place
match
1872
1872
draw
took
0–0
The
the
The
was
the
and
and
by
as
of
is
30
It
on
in
a
[Anagrams]
match
match
```
## Technologies
* C++

## Author
Łukasz Karasek