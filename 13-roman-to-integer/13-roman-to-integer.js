/**
 * @param {string} str
 * @returns {number}
 */
var romanToInt = function(str) {
   var values = {
     'I': 1,
     'V': 5,
     'X': 10,
     'L': 50,
     'C': 100,
     'D': 500,
     'M': 1000
   };
   var len = str.length;
   var ans = 0;
   for (var i = 0; i < len; ++i) {
       var cur = values[str[i]];
       if (i + 1 < len) {
           var next = values[str[i+1]];
           if (next == cur * 5) {
               ++i;
               cur = cur * 4;
           }
           else if (next == cur * 10) {
               ++i;
               cur = cur * 9;
           }
       }
       ans += cur;
   }
   return ans;
};
