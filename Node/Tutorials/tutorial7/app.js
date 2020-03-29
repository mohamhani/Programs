var http = require('http');
var fs = require('fs');

/*
var myReadStream = fs.createReadStream(__dirname + '/readMe.txt', 'utf8');
var myWriteStream = fs.createWriteStream(__dirname + '/writeFile.txt');


myReadStream.on('data', (chunk) => {
    console.log('new chunk received: ');
    myWriteStream.write(chunk);
});
*/

// Pipes are more convenient than manually trigering events and then manually writing streams

//myReadStream.pipe(myWriteStream);

var server = http.createServer(function(req, res){
    res.writeHead(200, {'Content-Type': 'text/plain'});
    var myReadStream = fs.createReadStream(__dirname + '/readMe.txt', 'utf8');
    myReadStream.pipe(res);
});

server.listen(3000, '127.0.0.1');
console.log('listening to port 3000 ....');