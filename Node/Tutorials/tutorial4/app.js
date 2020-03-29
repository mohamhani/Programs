var events = require('events');
var util = require('util');

var Person = function(name) {
    this.name = name;
};

util.inherits(Person, events.EventEmitter);

var mohamed = new Person('mohamed');
var warda = new Person('Warda');
var khadra = new Person('khadra');

var people = [mohamed, warda, khadra];

people.forEach(function(person){
    person.on('speak', function(msg){
        console.log(person.name + ' said ' + msg);
    });
});

warda.emit('speak', 'how are you doing moe');


