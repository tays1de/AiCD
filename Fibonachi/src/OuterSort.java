import java.io.*;
import java.util.Random;
import java.util.Scanner;

public class OuterSort {

    public static String whereTo = null;
    private static String serialMark = "---\n";

    public static int minimumInArray(int[] array){
        int index = 0;

        for(int i = 1; i < array.length; i++){
            if(array[i] < array[index])
                index = i;
        }

        return index;
    }

    public static void randomTestArrayFile(int n, int top, String fileName){
        Random rng = new Random();

        try {

            FileWriter writer = new FileWriter(fileName);

            for(int i = 0; i < n; i++){
                writer.write(Integer.toString(rng.nextInt(top + 1)) + "\n");

            }

            writer.close();


        } catch (IOException e) {
            System.out.println("Test file formation failed.");
            return;
        }

    }

    public static int separateSeries(String input, String output){

        int seriesCount = 0;
        StringBuilder resultString = new StringBuilder();

        int old = Integer.MIN_VALUE;
        int current;
        String line;
        try {

            Reader read = new FileReader(input);
            BufferedReader readFromFile = new BufferedReader(read);
            while((line = readFromFile.readLine()) != null){
                current = Integer.parseInt(line);
                if(current >= old){
                    resultString.append(line).append("\n");

                }else{
                    resultString.append(serialMark);
                    seriesCount++;
                    resultString.append(line).append("\n");
                }
                old = current;
            }
            resultString.append(serialMark);
            seriesCount++;

            readFromFile.close();


        } catch (FileNotFoundException e) {
            System.out.println("Input file not found.");
        } catch (IOException e) {
            System.out.println("I/O error detected.");
        }



        try {
            FileWriter writer = new FileWriter(output);
            writer.write(resultString.toString());
            writer.close();
            return seriesCount;
        } catch (IOException e) {
            System.out.println("Test file formation failed.");
            return 0;
        }
    }

    static boolean isFibonacci(int num){
        int prev1 = 1;
        int current = 1;
        int ex;
        while(num > current){
            ex = prev1 + current;
            prev1 = current;
            current = ex;
        }
        return num == current;
    }

    static int fibonacciCeil(int num){
        int prev1 = 1;
        int current = 1;
        int ex;
        while(num > current){
            ex = prev1 + current;
            prev1 = current;
            current = ex;
        }
        return current;
    }

    static int fibonacciFloor(int num){
        int prev1 = 1;
        int current = 1;
        int ex;
        while(num > current){
            ex = prev1 + current;
            prev1 = current;
            current = ex;
        }
        return prev1;
    }

    static int zeroesInArray(int[] array){
        int count = 0;

        for(int i = 0; i < array.length; i++){
            if(array[i] == 0){
                count++;
            }
        }

        return count;
    }

    static void fibonacciSort(String fileName){

        String[] files = new String[3];
        files[0] = ".\\TestFiles\\ExFile1.txt";
        files[1] = ".\\TestFiles\\ExFile2.txt";
        files[2] = ".\\TestFiles\\ExFile3.txt";

        FileWriter writeTo;

        String input = ".\\TestFiles\\NewInput.txt";

        int series = separateSeries(fileName, input);

        try{

            Reader read = new FileReader(input);
            BufferedReader readFromFile = new BufferedReader(read);

            int[] seriesCount = new int[3];
            BufferedReader[] exFiles = new BufferedReader[2];
            FileWriter[] writers = new FileWriter[2];
           /* for(int i = 0 ; i <3; i++){
                seriesCount[i] = 0;        ???????????
               // writers[i] = new FileWriter(files[i]);
            }*/
            for(int i = 0 ; i <2; i++){
                seriesCount[i] = 0;
                writers[i] = new FileWriter(files[i]);
            }

            String line;
            int i = 0;
            series = fibonacciFloor(fibonacciCeil(series) - 1);
            while(seriesCount[i] < series){
                line = readFromFile.readLine();
                writers[i].write(line + "\n");
                if(line.equals("---")){
                    seriesCount[i]++;
                }
            }
            i++;
            while((line = readFromFile.readLine()) != null){
                writers[i].write(line + "\n");
                if(line.equals("---")){
                    seriesCount[i]++;
                }
            }
            series = fibonacciFloor(series - 1);
            while(seriesCount[i] < series){
                writers[i].write("empty\n");
                writers[i].write(serialMark);
                seriesCount[i]++;
            }
            readFromFile.close();

            System.out.println();
            System.out.println(seriesCount[0]);
            System.out.println(seriesCount[1]);
            System.out.println(seriesCount[2]);
            System.out.println();

            for(int j = 0; j < 2; j++){
                writers[j].close();
            }

            int[] from = new int[2];
            from[0] = 0;
            from[1] = 1;

            int to = 2;
            int currentIndex;
            int notComplete = -1;

            while(seriesCount[0] + seriesCount[1] + seriesCount[2] > 1){

                for(int j = 0; j < 2; j++){
                    Reader buf = new FileReader(files[from[j]]);
                    exFiles[j] = new BufferedReader(buf);
                }

                writeTo = new FileWriter(files[to]);

                String[] mergeBuf = new String[2];



                do{
                    mergeBuf[0] = exFiles[0].readLine();
                    mergeBuf[1] = exFiles[1].readLine();
                    do{
                        if(mergeBuf[1].equals("empty")){
                            mergeBuf[1] = exFiles[1].readLine();
                            seriesCount[from[1]]--;
                            currentIndex = 0;
                            writeTo.write(mergeBuf[currentIndex] + "\n");
                            break;
                        }
                        if(Integer.parseInt(mergeBuf[0]) <= Integer.parseInt(mergeBuf[1])){
                            currentIndex = 0;
                        }
                        else{
                            currentIndex = 1;
                        }
                        writeTo.write(mergeBuf[currentIndex] + "\n");
                        mergeBuf[currentIndex] = exFiles[currentIndex].readLine();
                        if(mergeBuf[currentIndex].equals("---")){
                            seriesCount[from[currentIndex]]--;
                            currentIndex = (currentIndex + 1) % 2;
                            writeTo.write(mergeBuf[currentIndex] + "\n");
                            break;
                        }
                    }while(true);

                    while(!(mergeBuf[currentIndex] = exFiles[currentIndex].readLine()).equals("---")){
                        writeTo.write(mergeBuf[currentIndex] + "\n");
                    }
                    seriesCount[from[currentIndex]]--;


                }while(seriesCount[from[0]] > 0 && seriesCount[from[1]] > 0);

                writeTo.close();


                seriesCount[to] = separateSeries(files[to], files[to]);

                whereTo = files[to];
                for(int j = 0; j < 2; j++){
                    if(seriesCount[from[j]] == 0){
                        int tmp = to;
                        to = from[j];
                        from[j] = tmp;
                    }
                    else{
                        notComplete = j;
                    }
                }

                if(seriesCount[0]+seriesCount[1]+seriesCount[2]>1) {
                    StringBuilder cleanUp = new StringBuilder("");
                    while ((line = exFiles[notComplete].readLine()) != null) {
                        cleanUp.append(line).append("\n");
                    }
                    FileWriter rewrite = new FileWriter(files[from[notComplete]]);
                    rewrite.write(cleanUp.toString());
                    rewrite.close();
                }
                exFiles[0].close();
                exFiles[1].close();

                System.out.println();
                System.out.println(seriesCount[0]);
                System.out.println(seriesCount[1]);
                System.out.println(seriesCount[2]);
                System.out.println();

            }

        }
        catch(FileNotFoundException e){
            System.out.println("File not found.");
        }
        catch (IOException e) {
            System.out.println("I/O error detected.");
        }



    }



    public static void main(String[] args) {

        /*Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of elements in the test array: ");
        int n = input.nextInt();
        System.out.print("Enter the highest integer for the array: ");
        int top = input.nextInt();*/
        String name = ".\\TestFiles\\TestFile.txt";
        /*randomTestArrayFile(n, top, name);
        input.close();*/
        fibonacciSort(name);
        System.out.println("Finished.");
        System.out.println(OuterSort.whereTo);
    }

}
