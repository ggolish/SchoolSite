#!/usr/local/bin/node

var width=100;
var height=100;

var w = "#";
var row = "#";
for(var x = 0; x < width-2; x++) {
  row += ".";
  w += "#";
}
row += "#";
w += "#";

console.log(w);
for(var y = 0; y < height-2; y++) {
  console.log(row);
}
console.log(w);
