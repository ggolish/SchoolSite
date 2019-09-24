
// Global variables here:  These are accessible by all the functions:
var _ctx;
var obj;

function object_name() {
  this.property = value;
  this.method = function() {
  };
  this.draw = function() {
  };
  this.update = function() {
  };
}

function setup() {
  _ctx = document.getElementById("c").getContext("2d");
  // Define objects like images, player objects:
  
  obj = new object_name();
  //...
}

function update() {
  _ctx.clearRect(0, 0, 1024, 768);
  // Draw the screen
  // Use the object drawing routines:
}

