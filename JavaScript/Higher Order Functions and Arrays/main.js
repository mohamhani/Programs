const companies = [
    {name: "Company One", category: "Finance", start: 1981, end: 2003},
    {name: "Company Two", category: "Retail", start: 1992, end: 2008},
    {name: "Company Three", category: "Auto", start: 1999, end: 2007},
    {name: "Company Four", category: "Retail", start: 1989, end: 2010},
    {name: "Company Five", category: "Technology", start: 2009, end: 2014},
    {name: "Company Six", category: "Finance", start: 1987, end: 2010},
    {name: "Company Seven", category: "Auto", start: 1986, end: 1996},
    {name: "Company Eight", category: "Technology", start: 2011, end: 2016},
    {name: "Company Nine", category: "Retail", start: 1981, end: 1989}
  ];
  
const ages = [33, 12, 20, 16, 5, 54, 21, 44, 61, 13, 15, 45, 25, 64, 32];

/** 
// ForEach
companies.forEach(function(company) {
    console.log(company.name);
});
*/

/** 
// Filter
const canDrink = ages.filter((age) => age >= 21);

const retailCompanies = companies.filter(company => company.category == 'Retail');
*/

/**
// Map

// Create an array of company names
const companyNames = companies.map((company) => {
    return company.name;
});

// Create an array of company names and company start and end dates
const startandEndDates = companies.map((company) => {
    return `${company.name} [${company.start} - ${company.end}]`;
});

// Squareroute of ages
const agesSquare = ages.map(age => Math.sqrt(age));
*/

// Reduce
/** 
const ageSum = ages.reduce((total, age) => {
    return total + age;
}, 0);
*/