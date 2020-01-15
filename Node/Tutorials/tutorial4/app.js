var events = require('events');
var util = require('util');

var Person = function(name) {
    this.name = name;
};

util.inherits(Person, events.EventEmitter);

var mohamed = new Person('mohamed');
var farah = new Person('farah');
var khadra = new Person('khadra');

var people = [mohamed, farah, khadra];

people.forEach(function(person){
    person.on('speak', function(msg){
        console.log(person.name + ' said ' + msg);
    });
});

khadra.emit('speak', 'how are you doing moe');


