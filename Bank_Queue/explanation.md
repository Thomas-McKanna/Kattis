https://open.kattis.com/problems/bank

To solve this problem, you must identify a [greedy](https://en.wikipedia.org/wiki/Greedy_algorithm) strategy for deciding in what order to queue people. 

First, try to solve the problem by yourself. If you find you are spending more than 30 minutes to solve the problem, expand at the hint below. 

>! ## Solution
> 
> The greedy strategy is as follows: sort by deposit amounts, in decreasing order. Then place the customer with the highest deposit as far back as they can be placed in the queue. If the place is occupied, keep trying to place them earlier until an open spot is found, or the candidate is discarded since there is no more room. Repeat this process until all people have been considered.

> Below is the code which implements a solution. After that, there are some notes about the code itself.
> 
>```cpp
>#include <stdio.h>
>#include <utility>
>#include <algorithm>
>#include <cstring>
>
>using namespace std;
>
>typedef pair<int, int> pi;
>
>int main() {
>    int N, T, c, t, queue[10000];
>    pi people[10000];
>
>    scanf("%d %d", &N, &T);
>
>    for (int i = 0; i < N; i++) {
>        scanf("%d %d", &c, &t);
>        people[i] = pi(-c, t); // -c so that cash is sorted in >decreasing order
>    }
>
>    sort(people, people + N);
>
>    int ans = 0;
>    memset(queue, -1, sizeof(queue));
>    for (int i = 0; i < N; i++) {
>        c = -people[i].first; // undo the negation to cash we >did earlier
>        t = people[i].second;
>        for (int j = t; j >= 0; j--) {
>            if (queue[j] == -1) {
>                queue[j] = 1;
>                ans += c;
>                break;
>            }
>        }
>    }
>
>    printf("%d\n", ans);
>
>    return 0;
>}
> ```
> 
> There are several aspects of the code which deserve note:
> - I used `typedef pair<int, int> pi` to prevent having to type out a much more cumbersome and distracting name in the code. `pi` can be used in place of `pair<int, int>`.
> - One interesting characteristic of using `pair<int, int>` is that the `sort` function (made available by `<algorithm>`) sorts on the first value, and breaks ties by sorting on the second value. It doesn't apply to this problem, but it useful to know.
> - It is quicker to declare arrays with the maximum size defined in the problem than to use a dynamic data structures such as `vector`. Note that the entire array may not be used.
> - The older input/output functions `scanf` and `printf` from `<stdio.h>` are faster than using `cin` and `cout`. It's a small optimization, but one you may want to consider using.
> - `memset` (from `<cstring>`) is very useful for quickly initializing an array to a single value. The first argument is the array, the second argument is what to set each element to, and the third argument is how many elements (should normally use sizeof(array), which will be all elements).
> 
>**Questions, comments, improvements, mistakes? Comment below.**
