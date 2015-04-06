/**
 * @param {string} a
 * @param {string} b
 * @return {number}
 */
var compareVersion = function(a, b) {
    var as = a.split('.');
    var bs = b.split('.');
    var len = as.length > bs.length ? as.length : bs.length;
    for (var i = 0; i < len; ++i) {
        var pa = +as[i] || 0;
        var pb = +bs[i] || 0;
        if (pa > pb) {
          return 1;
        }
        if (pa < pb) {
          return -1;
        }
    }
    return 0;
};
