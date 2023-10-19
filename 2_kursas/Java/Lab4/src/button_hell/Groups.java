package button_hell;

import java.util.*;
import java.util.stream.Collectors;

import static button_hell.studList.filter;

public class Groups {
    static Map<String, ArrayList<String>> groupStud = new HashMap<String, ArrayList<String>>();
    static Map<String, ArrayList<String>> attendance = new HashMap<String, ArrayList<String>>();

    //setter
    public static void addGroup(String group) {
        groupStud.put(group, new ArrayList<String>());
    }

    public static void addStudents(String name, String group) {
        groupStud.get(group).add(name);
        attendance.put(name, new ArrayList<String>());
    }

    public static void addAttendance(String name, String year, String month, String day) {
        String temp = year + '-' + month + '-' + day;
        attendance.get(name).add(temp);
    }

    //Getters

    public static Object getGroups() {
        return groupStud.keySet();
    }

    public static Object getGroupsStuden(String Group) {
        return groupStud.get(Group).toArray();
    }

    public static Object getStudents() {
        return groupStud.values();
    }

    public Set getAttStuds() {
        return attendance.keySet();
    }

    public Object getAttendace(String group) {
        return attendance.get(group);
    }

    public static Object dataForList(String[] filter) {
        int i = 0;
        int studAmount = 0;

        Vector<String> Dates = new Vector<>();
        for (String key : Groups.attendance.keySet()) {
            for (int t = 0; t < Groups.attendance.get(key).size(); t++) {
                Dates.add(Groups.attendance.get(key).get(t));
            }
        }
        List<String> UniqueDates = Dates.stream().distinct().collect(Collectors.toList());
        UniqueDates.sort(Comparator.naturalOrder());


        for (String key : Groups.groupStud.keySet()) {
            for (int t = 0; t < groupStud.get(key).size(); t++) {
                studAmount++;
            }
        }
        String data[][] = new String[studAmount + 1][UniqueDates.size() + 2];

        for (String key : Groups.groupStud.keySet()) {
            for (int t = 0; t < groupStud.get(key).size(); t++) {
                data[i][0] = key;
                data[i][1] = groupStud.get(key).get(t);
                if (studList.filter[2] == "True") {
                    int h = 0;
                    for (int s = UniqueDates.indexOf(studList.filter[0]); s < UniqueDates.indexOf(studList.filter[1]) + 1; s++) {
                        if (attendance.get(data[i][1]).contains(UniqueDates.get(s)))
                            data[i][h + 2] = "1";
                        else {
                            data[i][h + 2] = "0";
                        }
                        h++;
                    }
                } else {
                    for (int s = 0; s < UniqueDates.size(); s++) {
                        if (attendance.get(data[i][1]).contains(UniqueDates.get(s)))
                            data[i][s + 2] = "1";
                        else {
                            data[i][s + 2] = "0";
                        }
                    }
                }
                i++;
            }
        }

        return data;
    }

    public static Object[] collsForList(String[] filter) {
        Vector<String> Dates = new Vector<>();
        for (String key : Groups.attendance.keySet()) {
            for (int t = 0; t < Groups.attendance.get(key).size(); t++) {
                Dates.add(Groups.attendance.get(key).get(t));
            }
        }

        List<String> UniqueDates = Dates.stream().distinct().collect(Collectors.toList());
        UniqueDates.sort(Comparator.naturalOrder());


        if (studList.filter[2] == "True") {
            String[] temp = new String[UniqueDates.indexOf(filter[1]) + 3];
            temp[0] = "Grupe";
            temp[1] = "Vardas";
            int s = 0;
            int start = UniqueDates.indexOf(filter[0]);
            int fin = UniqueDates.indexOf(filter[1]);
            for (int i = start; i < fin + 1; ++i) {
                temp[s + 2] = String.valueOf(UniqueDates.get(i));
                s++;
            }
            return temp;
        } else {
            String[] temp = new String[UniqueDates.size() + 2];
            temp[0] = "Grupe";
            temp[1] = "Vardas";
            for (int i = 0; i < UniqueDates.size(); ++i) {
                temp[i + 2] = String.valueOf(UniqueDates.get(i));
            }
            return temp;
        }
    }

    public static String[][] forOutput() {
        int studAmount = 0;
        for (String key : Groups.groupStud.keySet()) {
            for (int t = 0; t < groupStud.get(key).size(); t++) {
                studAmount++;
            }
        }
        String[] tempCol = (String[]) collsForList(filter);
        String[][] tempData = (String[][]) dataForList(filter);
        System.out.println(tempCol[0]);
        System.out.println(tempCol[2]);
        String[][] data = new String[tempData.length + 1][tempCol.length + 1];
        for (int i = 0; i < tempCol.length; i++) {
            data[0][i] = tempCol[i];
        }
        for (int i = 0; i < tempData.length; i++) {
            for (int a = 0; a < tempCol.length; a++) {
                data[i + 1][a] = tempData[i][a];
            }
        }
        return data;
    }
}
