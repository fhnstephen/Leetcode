/**
 * @param {string} str
 * @returns {string}
 */
var reverseWords = function(str) {
    return str.split(" ").filter(function(x) {return x.length;}).reverse().join(" ");
};
