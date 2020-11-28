https://open.kattis.com/problems/bank

To solve this problem, you should use the [bisection method](https://en.wikipedia.org/wiki/Bisection_method). Ask yourself: what is the function in this problem? What would constitute your function being positive? What would constitute your function being negative? What value are you trying to zero in on?

First, try to solve the problem by yourself. If you find you are spending more than 30 minutes to solve the problem, expand at the hint below. 

>! ## Solution
> 
> This is the solution I came up with. We know that at some point while going down the mountain the monk will occupy the same position as when he is going up the mountain. For this problem, the function is whether or not the monk has passed this point where he was in the same position both going up and down. 

> Below is the code which implements a solution. After that, there is an explanation of various parts of the code.
> 
>```cpp
>#include <iostream>
>#include <cmath>
>#include <iomanip>
>
>using namespace std;
>
>int a, d, asc_h[5001], asc_t[5001], dsc_h[5001], dsc_t[5001], mountain_h = 0;
>
>bool monk_passed_same_spot(double time) {
>    double monk_asc_h = 0.0, monk_dsc_h = 0.0;
>    double t = 0;
>    int i = 0;
>    while (i < a && t < time) {
>        monk_asc_h += min(
>            (double) asc_h[i], 
>            ((time - t) / asc_t[i]) * asc_h[i]
>        );
>        t += asc_t[i];
>        i++;
>    }
>    t = 0;
>    i = 0;
>    while (i < d && t < time) {
>        monk_dsc_h -= min(
>            (double) dsc_h[i], 
>            ((time - t) / dsc_t[i]) * dsc_h[i]
>        );
>        t += dsc_t[i];
>        i++;
>    }
>    return (mountain_h + monk_dsc_h) <= monk_asc_h;
>}
>
>int main() {
>    int temp;
>    cin >> a >> d;
>
>    for (int i = 0; i < a; i++) {
>        cin >> temp;
>        asc_h[i] = temp;
>        cin >> temp;
>        asc_t[i] = temp;
>    }
>
>    for (int i = 0; i < d; i++) {
>        cin >> temp;
>        dsc_h[i] = temp;
>        cin >> temp;
>        dsc_t[i] = temp;
>    }
>
>    for (int i = 0; i < a; i++) {
>        mountain_h += asc_h[i];
>    }
>
>    double hi = 100 * 5000 + 1;
>    double lo = 0.0;
>    double mid;
>
>    while (fabs(hi - lo) > 1e-9) {
>        mid = (hi + lo) / 2.0;
>        if (monk_passed_same_spot(mid))
>            hi = mid;
>        else
>            lo = mid;
>    }
>
>    cout << setprecision(9) << fixed << hi << endl;
>
>    return 0;
>}
> ```
> 
> There are several aspects of the code which deserve note:
> - I make arrays asc_h, asc_t, dsc_h, dsc_t to represent the array of segment heights and times for both ascent and descent. Notice that I just allocate space for the maximum possible number of segments, thus avoiding the need for dynamic storage structures, like vector.
> - For the `monk_passed_same_point` function, I calculate how far the monk has traveled up the mountain (given the passed in time), and then how far the monk has traveled down the mountain (given the passed in time). The trickiest thing here is that there are cases where only part of a segment is completed, which is why we taken the minimum of the segment height or the percentage of the segment height that will be completed with the remaining time (notice that the second argument to the `min` function will always be a percentage greater than 100%, unless the remaining time is less than what the segment requires.)
> - The `main` function starts by reading in the input. It then calculated the height of the mountain, which is used in the `monk_passed_same_point` function to determine if the monks have crossed paths. It finishes with the typical bisection method algorithm, and prints the answer to the desired precision.
> - Our upper bound is 100 * 5000 + 1 because there are at most 5000 segments and each segment can take at most 100 seconds. I add 1 for good measure. It may not be necessary but it only ensures our bounds are "more" than correct, and allows us to not have to worry if our boundary is *exactly* correct. Off by one errors are a pain and I try to avoid them if possible.
> 
>**Questions, comments, improvements, mistakes? Comment below.**
