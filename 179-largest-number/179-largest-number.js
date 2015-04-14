var largestNumber = function(num) {
    num.sort(function(a, b) {
       var as = a.toString();
       var bs = b.toString();
       return as + bs > bs + as ? -1 : 1;
    });
    var ans = num.join("");
    while (ans[0] == "0" && ans.length > 1) ans = ans.substr(1);
    return ans;
};
