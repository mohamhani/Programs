var http = require('http');
var fs = require('fs');


var readFile = fs.readFileSync('readMe.txt', 'utf8');

var server = http.createServer(function(req, res){
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end(readFile);
});

server.listen(3000, '127.0.0.1');
console.log('listening to port 3000 ....');


