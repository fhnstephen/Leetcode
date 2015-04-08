/**
 * @param {string} s
 * @returns {number}
 */
var lengthOfLastWord = function(s) {
    var a = s.split(' ');
    var len = a.length;
    if (!len) return 0;
    var i = len - 1;
    while (i && !a[i].length) --i;
    return a[i].length;
};
