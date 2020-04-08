import React, {useContext} from 'react';
import { BookContext } from '../contexts/BookContext';

const BookDetails = ({book}) => {
    const {dispatch} = useContext(BookContext);
    return (
        <li onClick={() => dispatch({type: 'REMOVE_BOOK', id: book.id})}>
            <div className="title">Title: {book.title}</div>
            <div className="author">Author: {book.author}</div>
        </li>
    );
}
 
export default BookDetails;