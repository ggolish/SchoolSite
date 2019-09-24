#!/usr/local/bin/node

// Creates a web-socket server (listens for connections):
var WebSocketServer = require("/usr/local/lib/node_modules/ws").Server;
// Bind the server to listen for connections on port 60000:
var server = new WebSocketServer({port: 60000});

// Listen for connections to the server:
server.on("connection", function(client) {
  // A client has connected, so we'll add a message listener:
  client.on("message", function(message) {
    // Output all the messages the clients send:
//    console.log("message: %s", message);
    // Broadcast the message the client sent to all the connected clients,
    // including the orginal sender:
    for(var i in server.clients) {
      server.clients[i].send(message);
    }
  });
  // Send the client a connection message when they first connect:
  client.send(JSON.stringify({name: "", message: "Connected!"}));
});
