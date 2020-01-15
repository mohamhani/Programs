var fs = require('fs');

var readFile = fs.readFileSync('readfile.txt', 'utf8');

//console.log(readFile);

fs.writeFileSync('outputfile.txt', readFile);

//Assync functions

fs.readFile('readFile.txt', 'utf8', function(err, data){
    fs.writeFile('asyncoutputfile', data, (err) => {
        if(err){
            throw err;
        }
    });
});