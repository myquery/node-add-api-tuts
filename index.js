const MyTeam = require("./build/Release/node-api-tuts.node")

try{
    ((arr)=> {
        arr.map((item)=> {
            MyTeam.addTeamMember(item)
        })
        console.log(MyTeam.getTeamList())  
    })([
        "John Doe", 
        "Jane Doe", 
        "Suzan Doe", 
        "Jack Doe", 
        "Mary Doe", 
        "Agba Doe", 
        "Ogbologbo Doe", 
        "Musa Doe", 
        "Emeka Doe"
    ])

}catch(e){
    console.error(e.message)
}

//console.log(addon.hello("Stanley"))