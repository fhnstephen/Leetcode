/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    var ans = yourPow(x, n < 0 ? -n : n);
    if (n < 0) return 1.0/ans; else return ans;
};

var yourPow = function(x, n) {
    if (n === 0) return 1;
    var half = myPow(x, n / 2);
    half = half * half;
    if (n & 1) half = half * x;
    return half;
}
