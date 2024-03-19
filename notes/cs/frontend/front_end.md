# Front End Notes

## HTML CSS

- Box model, all HTML elements are boxes.

  - Margin: 外边框
  - Border: 边框
  - padding: 内边距
  - Content: the inside content of box

  total width = css width + leftrightpadding+leftrightborder+leftrightmargin

- css value copy

  values in box attributes are in order of: up right down left.(4 value)

  ```css
  div#shit {
  	margin: 1px 2px  /*up 1 right 2 down 1 left 2 */
  }
  ```

  copy logic: 

  - If 3 values are given, the 4th value is copied from the second
  - If 2 values are given, the 3rd value is copied from the first, the 4th value is copied from the 2nd
  - If 1 value is given, the rests are copied from this one.

- id and class

  ```css
  div#shit {} /*id is shit*/
  .fuck {} /*class is fuck*/
  ```

  child element selector: use `>`

  ```css
  div#header > h1 {}
  ```

- body default margin：8px, if you need layout stick to border, use `body {margin: 0;}`

## Nginx

1. how to start a nginx:

   `nginx -s signal`

   signal: reload, reload configuration file: `nginx.conf`at /etc/nginx/nginx.conf

2. about configuration

   - finds `/etc/nginx/nginx.conf`first

   define sites at `/etc/nginx/sites-available` and links them at `/etc/nginx/sites-enabled`

   - nginx finds server base on `Host`of an http `GET` request

     eg. `http://localhost/hello.html`, Host is `localhost`

     `nginx`matches `Host`with `server_name`in `server` directive.

     ```
     http {
     	server {
     		server_name localhost;
     		location {
     		
     		}
     		...
     	}
     }
     ```

   - if no `server_name`matches, use `default_server`
   - nginx select specific server, and chooses one `location` to send files

3. server_name is a different concept from DNS

   DNS server maps your URL to ip address, and send packages. `Host` is in `http` proxy packages.

## JavaScript

- history

  Created by Brendan Eich at Netscape. Originally call LiveScript. 

  > Several months later, Microsoft released JScript with Internet Explorer 3. 
  >
  > Several months after that, Netscape submitted JavaScript to [Ecma International](https://www.ecma-international.org/), a European standards organization, which resulted in the first edition of the [ECMAScript](https://developer.mozilla.org/en-US/docs/Glossary/ECMAScript) standard that year. 
  >
  > The standard received a significant update as ECMAScript edition 3 in 1999. 
  >
  > The fourth edition was abandoned, due to political differences concerning language complexity. 
  >
  > Many parts of the fourth edition formed the basis for ECMAScript edition 5, published in December 2009
  >
  > and for the 6th major edition of the standard, published in June 2015. 
  >
  > Since then a yearly edition has been published. For example, the [13th edition](https://www.ecma-international.org/publications-and-standards/standards/ecma-262/) was published in June 2022.

- Numbers

`Number` : double precision in 64-bit binary format. `-(2^53-1)`to`2^53-1`

 `BigInt`

- Strings

- null

- boolean type

- `var` is visible inside the function, outside the block.

- `let` is visible only inside the block.

- Objects. Javascript supports object oriented programming, with object prototype as "class" in other language.

- Functions

  - `arguments` stores the arguments passed into the function

    ```javascript
    function add() {
    	let sum = 0;
        for(const i of arguments) {
            sum += i;
        }
        return sum;
    }
    // or 
    ```

    Or using **Rest parameter syntax**

    ```javascript
    function add(...args) {
    //...
    }
    ```

  - call `add` with `add(2,3,4,5)` or `apply()` function, `add.apply(null, [1,2,2,3])`

  - Anonymous functions 

    > In practice, anonymous functions are typically used as arguments to other functions or are made callable by immediately assigning them to a variable that can be used to invoke the function

    ```javascript
    let add = function() {
        let sum = 0;
        //...
        return sum;
    }
    ```

  - Immediately invoked function expression(**IIFE**)

    ```javascript
    (function() {})();
    ```

    an example with recursive function:

    ```javascript
    const charsInBody = (function counter(elm) {
      if (elm.nodeType == 3) { // TEXT_NODE
        return elm.nodeValue.length;
      }
      let count = 0;
      for (let i = 0, child; child = elm.childNodes[i]; i++) {
        count += counter(child);
      }
      return count;
    })(document.body);
    ```

  - Functions are objects!

    ```javascript
    function makePerson(first, last) {
      return {
        first: first,
        last: last,
        fullName() {
          return `${this.first} ${this.last}`;
        },
        fullNameReversed() {
          return `${this.last}, ${this.first}`;
        }
      };
    }
    
    const s = makePerson('Simon', 'Willison');
    s.fullName(); // "Simon Willison"
    s.fullNameReversed(); // "Willison, Simon"
    ```

  - `prototype` function, shared by all instances

    ```javascript
    function NewShit(){}
    NewShit.prototype.callshit = function(){}
    ```

  - you can add functions to prototype of build-in objects in Javascript

    ```javascript
    const s = 'Hellopiggy';
    String.prototype.reversed = function() {}
    ```

- Closures, looks like python decorator

  ```javascript
  function makeAdder(a) {
    return function(b) {
      return a + b;
    };
  }
  const add5 = makeAdder(5);
  const add20 = makeAdder(20);
  add5(6); // ?
  add20(7); // ?
  ```

- 

## React

React is a JavaScript library

- `this` pointer problem

I haved been stuck with a bug of javascript keyword`this` in react official tutorial:

```react
Class Square extends React.Component {
    constructor(props) {
        super(props);
        this.state = {value: null};
    }
	render() {
        <button
            className="square"
            onClick={() => {this.setState({value:'X'})}}     // success
			// onClick={function(){this.setState({value:'X'})}} failed
            >sth</button>
    }
}
```

In `render` function of class `Square`, I implemented `onClick` attribute of a button. The value of `this.state` was set successfully if I use pointer function `() => {}`, while failed at using normally declared function `function() {}`.

I use `console.log(this)` to check what `this` really points to(`onClick()={()=>{console.log(this);}}`), and find out `undefined` in the case of normally function definition:

```javascript
//Square {props: {…}, context: {…}, refs: {…}, updater: {…}, state: {…}, …}  // ()=>{} output
//undefined // function() {} output
```

- javascript function in a class

  **Three** methods to make it works:

  1) 

  ```react
  class A {
      constructor(props){
  		// This binding is necessary to make `this` work in the callback
  	    this.handleClick = this.handleClick.bind(this);
      }
  	fun(){}
  	render(){
  		return <button onClick={this.fun}>test</button>
  	}
  }
  ```


2. 

   ```react
   class A{
    fun(){}
       render(){return <button onClick={() => this.fun()}></button>;}
   }
   ```

3. 

   ```react
   class A {
    	fun = () => {
    	
    	};
    	render() {return <button onClick={this.fun}></button>;}
   }
   ```

- In JavaScript, `true && expression` always evaluates to `expression`, and `false && expression` always evaluates to `false`.

- top down data flow. when components need to share state to each other, move this state to the nearest ancestor.

- **Hooks**

  

## Vue

## Node.js

## Django