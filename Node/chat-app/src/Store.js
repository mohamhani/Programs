import React from 'react';
import io from 'socket.io-client';

export const CTX = React.createContext();

const initState = {
    general: [
        {from: 'Amandeep', msg: 'Hello Moe'},
    ],
    topic2: [
        {from: 'Khadra', msg: 'Waryaa iska waran'},
    ]
}

const reducer = (state, action) => {
    const {from, msg, topic} = action.payload;
    switch(action.type) {
        case 'RECEIVE_MESSAGE':
            return {
                ...state,
                [topic]: [
                    ...state[topic],
                    {from, msg}
                ]
            }
        default:
            return state
    }
};

let socket;

const sendChatAction = (value) => {
    socket.emit('chat message', value);
}

const Store = (props) => {

    const [allChats, dispatch] = React.useReducer(reducer, initState);
    console.log(allChats);

    if(!socket) {
        socket = io(':3001');
        socket.on('chat message', (message) => {
            dispatch({type:'RECEIVE_MESSAGE', payload: message});
        });
    }

    const user = 'Mohamed' + Math.random(100).toFixed(2);

    return (
        <CTX.Provider value={{allChats, sendChatAction, user}}>
            {props.children}
        </CTX.Provider>
    )
}

export default Store;