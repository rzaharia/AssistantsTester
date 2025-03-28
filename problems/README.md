# LLM-Based Naming Problems

This folder contains a collection of **naming problems** designed to evaluate how well large language models (LLMs) can understand code and generate appropriate function names based on **x86/x64 disassembly code**.

## 📌 Purpose  
The goal of this study is to analyze the effectiveness of LLMs in:  
- Understanding disassembled code at the function level.  
- Generating meaningful and appropriate function names.  
- Identifying patterns in LLM-generated names and evaluating their accuracy.  

## 🧪 Methodology  
1. **Selection of Problems:**  
   - We select **70 functions** that are self-contained, ensuring that an LLM has the full context needed for analysis.  
   - The problems were inspired by mathematical exercises from [w3resource](https://www.w3resource.com/c-programming-exercises/math/index.php).  

2. **LLM Querying:**  
   - Each function is presented to multiple LLMs (in our case, 2, Gemini 1.5 PRO and GPT 4o).  
   - Each LLM generates **five** suggested names per function.  

3. **Data Collection & Extraction:**  
   - The LLM outputs are collected and structured for easier evaluation.  

4. **Evaluation & Rating:**  
   - Each LLM-generated name is manually reviewed and categorized into one of three correctness levels:  
     - **(1) Clearly Indicates Behavior** – The name correctly describes the function’s purpose.  
     - **(2) Descriptive but Not Concise** – The name is accurate but overly detailed (e.g., *Describes swapping lines in a matrix* instead of *SwapMatrixLines*).  
     - **(3) Incorrect** – The name does not relate to the function’s actual behavior.  

## 📂 Folder Structure  

### 📁 assistants_results/  
Contains the LLM outputs for each problem. Each problem is stored in a separate folder, which includes the following files:  
- **output.json** – Extracted LLM answers from the visual interface.  
- **pX.gemini.gview** – Gemini’s response in text format.  
- **pX.gpt4o.gview** – GPT-4o’s response in text format.  
- **voted.json** – Manual ratings for each LLM-generated function name.  

(*Here, "pX" refers to a specific problem, e.g., `p1.gemini.gview` and `p1.gpt4o.gview` for problem 1.*)  

### 📁 sources/  
Contains the **original source code** used for the evaluation.  

## 🗃️ List of Problems

Below is the list of 70 problems used in this study. Each problem is named sequentially (e.g., `p1`, `p2`, etc.) and corresponds to a specific function analyzed for LLM-based naming evaluation.

1. **p1** - Reverse the digits of a given integer.  
2. **p2** - Check whether an integer is a palindrome.  
3. **p3** - Divide two integers without using multiplication, division, or mod operators.  
4. **p4** - Calculate `x` raised to the power `n`.  
5. **p5** - Calculate the factorial of a number.  
6. **p6** - Check if a given string can be interpreted as a decimal number.  
7. **p7** - Check if a number is a Fibonacci number using a loop.  
8. **p8** - Get the Excel column title corresponding to a given column number.  
9. **p9** - Get the column number corresponding to an Excel column title.  
10. **p10** - Find the number of trailing zeroes in a factorial.  
11. **p11** - Count the total number of digits `1` appearing in numbers ≤ `n`.  
12. **p12** - Repeatedly sum all digits of a number until one digit remains.  
13. **p13** - Check if an integer is a power of three.  
14. **p14** - Count the number of 1's in the binary representation of numbers from `0` to `n`.  
15. **p15** - Get the maximum product after breaking an integer into at least two positive integers.  
16. **p16** - Print numbers from `1` to `N` in lexicographic order.  
17. **p17** - Find the nth digit in the sequence of numbers `1` to `n`.  
18. **p18** - Find the total number of full staircase rows that can be formed from a given number of dice.  
19. **p19** - Find the square root of a number using the Babylonian method.  
20. **p20** - Multiply two integers without using multiplication, division, bitwise operators, or loops.  
21. **p21** - Calculate the average (mean) of a stream of numbers.  
22. **p22** - Count numbers without the digit `7` from `1` to a given number.  
23. **p23** - Find the next smallest palindrome of a given number.  
24. **p24** - Calculate `e^x` using the sum of the first `n` terms of the Taylor Series.  
25. **p25** - Print all prime factors of a number.  
26. **p26** - Check if a number is a Fibonacci number using a formula.  
27. **p27** - Multiply two numbers using bitwise operators.  
28. **p28** - Find the angle between the hour and minute hands of a clock.  
29. **p29** - Get the smallest number of square numbers that sum to `n`.  
30. **p30** - Count all numbers with unique digits of length `x` within a given range.  
31. **p31** - Find the largest number that can be generated by swapping at most two digits once.  
32. **p32** - Check if an integer can be expressed as the sum of a non-negative integer and its reverse.  
33. **p33** - Count the digits in a number that divide it.  
34. **p34** - Create a multiplication table of size `m × n` and find the kth smallest element.  
35. **p35** - Find all prime factors of a given number.  
36. **p36** - Count common factors of two given integers.  
37. **p37** - Count numbers whose digits are unique from `1` to a given integer.  
38. **p38** - Count numbers from `1` to `n` whose digit sums are odd.  
39. **p39** - Find the greatest common divisor (GCD) of two numbers.  
40. **p40** - Find the least common multiple (LCM) of two numbers.  
41. **p41** - Check if a given number is prime.  
42. **p42** - Print the first `n` prime numbers.  
43. **p43** - Search for an element in a sorted array using binary search.  
44. **p44** - Find the maximum and minimum elements in an array.  
45. **p45** - Reverse an array.  
46. **p46** - Rotate an array by `k` positions.  
47. **p47** - Find the sum of all elements in an array.  
48. **p48** - Find the average of all elements in an array.  
49. **p49** - Find the median of an array.  
50. **p50** - Find the mode of an array.  
51. **p51** - Find the sum of digits of a number.  
52. **p52** - Check if a number is an Armstrong number.  
53. **p53** - Check if a number is a perfect square.  
54. **p54** - Convert temperature between Celsius and Fahrenheit.  
55. **p55** - Calculate simple and compound interest.  
56. **p56** - Calculate the sum of divisors of a number.  
57. **p57** - Check if a number is a Kaprekar number.  
58. **p58** - Count the number of vowels in a string.  
59. **p59** - Check if a string is a valid Base64-encoded string.  
60. **p60** - Check if a string contains spaces.  
61. **p61** - Find the GCD of an array of numbers.  
62. **p62** - Calculate the nth triangular number.  
63. **p63** - Determine if a number is a Harshad (Niven) number.  
64. **p64** - Replace all spaces in a string with the digit `0`.  
65. **p65** - Check if a number is a power of two (using a loop).  
66. **p66** - Check if two strings are anagrams.  
67. **p67** - Check if a number is a power of two (using bitwise operations).  
68. **p68** - Replace all vowels in a string with a specific character.  
69. **p69** - Find the second largest element in an array.  
70. **p70** - Check if an array is sorted in ascending order.  

---

Each problem is stored as a **source file** in `sources/` and its corresponding LLM-generated outputs and evaluations are in `assistants_results/`.  
Refer to the respective files for more details on how each problem was tested and analyzed.