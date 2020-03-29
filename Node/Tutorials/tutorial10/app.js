var http = require('http');
var fs = require('fs');

var server = http.createServer(function(req, res){
    
    if(req.url === '/home' || req.url === '/') {
        res.writeHead(200, {'Content-Type': 'text/html'});
        var myReadStream = fs.createReadStream(__dirname + '/index.html');
        myReadStream.pipe(res);
    } else if(req.url === '/contact') {
        res.writeHead(200, {'Content-Type': 'text/html'});
        var myReadStream = fs.createReadStream(__dirname + '/contact.html');
        myReadStream.pipe(res);
    }
    
});

server.listen(3000, '127.0.0.1');
console.log('listening to port 3000 ....');