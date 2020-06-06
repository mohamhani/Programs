var app = require('express')();
var http = require('http').createServer(app);
var io = require('socket.io')(http);

app.get('/', (req, res) => {
    res.send('<h1>')
});

io.on('connection', (socket) => {
    console.log('user connected');
    socket.on('chat message', (message) => {
        console.log(`message: ${message.msg}`);
        io.emit('chat message', message);
    });
});

http.listen(3001, () => {
    console.log('Server is listening on 3001...');
});