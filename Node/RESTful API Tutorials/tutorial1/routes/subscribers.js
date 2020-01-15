const express = require('express');
const router = express.Router();
const Subscriber = require('../models/subscriber');

// Getting all subscribers
router.get('/', async (req, res) => {
    try {
        const subscriber = await Subscriber.find();
        res.json(subscriber);
    } catch (err){
        res.status(500).json({message: err.message});
    }
});

// Getting one subscriber
 router.get('/:id', getSubscriber, (req, res) => {
    res.send(res.subscriber);
});

// Creating a subscriber
router.post('/', async (req, res) => {
    const subscriber = new Subscriber({
        name: req.body.name,
        subscribedToChannel: req.body.subscribedToChannel
    });

    try {
        const newSubscriber = await subscriber.save();
        res.status(201).json(newSubscriber);
    } catch (err) {
        res.status(400).json({message: err.message});
    }
});

// Updating a subscriber 
router.patch('/:id', getSubscriber, async (req, res) => {
    if(req.body.name != null) {
        res.subscriber.name = req.body.name;
    }
    if(req.body.subscribedToChannel != null) {
        res.subscriber.subscribedToChannel = req.body.subscribedToChannel;
    }
    try {
        const updatedSubscriber = await res.subscriber.save();
        res.json(updatedSubscriber);
    } catch (err) {
        res.status(400).json({message: err.message});
    }
});

// Deleting a subscriber
router.delete('/:id', getSubscriber, async (req, res) => {
    try {
        await res.subscriber.remove();
        res.json({message: 'Deleted subscriber'});
    } catch (err) {
        return res.status(500).json({message: err.message});
    }
});

// A middleware function
async function getSubscriber(req, res, next) {
    let subscriber;
    try {
        subscriber = await Subscriber.findById(req.params.id);
        if(subscriber == null) {
            return res.status(404).json({message: 'Cannot find subscriber'});
        }
    } catch (err) {
        return res.status(500).json({message: err.message});
    }
    res.subscriber = subscriber;
    next();
}

module.exports = router;