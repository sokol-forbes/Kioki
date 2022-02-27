const alphabet = [
  "а","б","в","г","д","е","ё","ж","з","и",
  "й","к","л","м","н","о","п","р","с","т",
  "у","ф","х","ц","ч",
  "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я",];
const key = require("./out.json").key.toLowerCase().split("");
console.log("Ключевая фраза ", key.join(""));
const input = require("./out.json").input
  .toLowerCase()
  .split(" ")
  .join("_");
const obj = [];
const matrix = [];
let id = 1;
 
for (let i = 0; true; i++) {
  if (key.length * i > input.length) {
    break;
  }
  matrix.push(
    input
      .substring(
        key.length * i,
        key.length * (i + 1) <= input.length
          ? key.length * (i + 1)
          : input.length
      )
      .split("")
  );
}
 
alphabet.forEach((c) => {
  while (true) {
    const a = key.findIndex((val) => (val === c ? val : null));
 
    if (a === -1) {
      break;
    }
 
    matrix.forEach((row) => {
      row[a] = { key: row[a], val: id };
    });
 
    key[a] = "";
    id++;
  }
});
 
for (let i = 0; i < matrix.length; i++) {
  const row = matrix[i];
 
  row.sort((a, b) => {
    if (a.val > b.val) {
      return 1;
    }
 
    return -1;
  });
 
  matrix[i] = row.map((val) => val.key).join("");
}
 console.log("\nИсходный текст ",input);
console.log("\nШифртекст: ",matrix.join(""),"\n");