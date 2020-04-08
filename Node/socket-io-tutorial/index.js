var express = require('express');
var socket = require('socket.io');

// App setup
var app = express();
var server = app.listen(3000, () => {
    console.log('Listening to port 3000...');
});

//Static files
app.use(express.static('public'));

//Socket setup
var io = socket(server);

io.on('connection', (socket) => {
    console.log(`Socket has made a connection`);

    socket.on('chat', (data) => {
        io.sockets.emit('chat', data);
    });

    socket.on('typing', (data) => {
        socket.broadcast.emit('typing', data);
    });
});
