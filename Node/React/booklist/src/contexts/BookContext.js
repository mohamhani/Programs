import React, {createContext, useReducer} from 'react';
import { bookReducer } from '../reducers/bookReducer';

export const BookContext = createContext();

const BookContextProvider = (props) => {
    const [books, dispatch] = useReducer(bookReducer, [
        {title: 'The Name of The Wind', author: 'Patrick Rothfuss',id: 1},
        {title: 'The Way of Kings', author: 'Brandon Sanderson',id: 2},
        {title: 'The Final Empire', author: 'Brandon Sanderson',id: 3},
        {title: 'The Hero of Ages', author: 'Brandon Sanderson',id: 4}
    ]);

    return (
        <BookContext.Provider value={{books, dispatch}}>
            {props.children}
        </BookContext.Provider>
    );
}
 
export default BookContextProvider;