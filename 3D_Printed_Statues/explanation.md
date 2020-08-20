https://open.kattis.com/problems/3dprinter

To solve this problem, you must identify the a strategy for finding the minimum number of days to print at least *n* statues. If your code is getting long, you are probably over-complicating it.

Try to solve the problem. After that, expand the details below.

>! ## Solution
>! 
>! The key is to recognize that the fastest way to print *n* statues is to double your number of printing machines until you have at least *n* printing machines. It is convenient to use the [logarithm](https://en.wikipedia.org/wiki/Binary_logarithm#:~:text=The%20binary%20logarithm%20is%20the,the%20power%20of%20two%20function.&text=The%20integer%20part%20of%20a,of%20a%20floating%20point%20value.) (base 2) of the number of machines in order to determine how many days have passed. 
>! 
>! ### Iterative Approach
>! 
>! The term 'iterative' just means that we are using a loop to determine the answer.
>! 
>! ```python
>! from math import log2
>! 
>! num_statues = int(input())
>! 
>! num_machines = 1
>! while True:
>!     if num_machines >= num_statues:
>!         num_days = log2(counter) + 1
>!         print(int(num_days))
>!         break
>!     num_machines *= 2
>! ```
>! 
>! ### Direct Approach
>! 
>! You can also directly calculate the answer using the logarithm of how many statues are needed. We add 1 since we start with one printing machine. We round up (ceil, short for ceiling) because we cannot use partial days.
>! 
>! ```python
>! from math import log2, ceil
>! num_statues = int(input())
>! log_num_statues = log2(num_statues) + 1
>! days_needed = ceil(log_num_statues) # round up to nearest whole number
>! print(days_needed)
>! ```
>!
>!**Questions, comments, improvements, mistakes? Comment below.**
