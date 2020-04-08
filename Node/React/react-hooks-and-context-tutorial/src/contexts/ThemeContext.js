import React, {createContext, Component} from 'react';

export const ThemeContext = createContext();

class ThemeContextProvider extends Component {
    state = {
        isLightTheme: false,
        light: {text:'#555', ui: '#ddd', backGround: '#eee'},
        dark: {text:'#ddd', ui: '#333', backGround: '#555'}
    }
    toggleTheme = () => {
        this.setState({isLightTheme: !this.state.isLightTheme});
    }
    render() { 
        return (
            <ThemeContext.Provider value={{...this.state, toggleTheme: this.toggleTheme}}>
                {this.props.children}
            </ThemeContext.Provider>
        );
    }
}
 
export default ThemeContextProvider;