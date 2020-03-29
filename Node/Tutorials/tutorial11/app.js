var express = require('express');

var app = express();

app.get('/', (req, res) => {
    res.sendFile(__dirname + '/index.html');
});

app.get('/contact', (req, res) => {
    res.sendFile(__dirname + '/contact.html');
});

app.get('/profile/:id', (req, res) => {
    res.send('You have requested to see a profile with the id of ' + req.params.id);
});

app.listen(3000);